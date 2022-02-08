from ctypes import CDLL, POINTER, \
    c_int, c_char_p, c_size_t, byref, create_string_buffer

# replace the below path with the path to the built dll/dylib (target libjd in cmake)
_backend_binding_lib_path = r'..\..\build\debug\libjd.dylib'
# _backend_binding_lib_path = r'..\..\build\debug\libjd.dll'
# _backend_binding_lib_path = r'..\..\build\debug\libjd.so'

"""
int decompile(const char* input, size_t in_len, char* output, size_t* out_len)
"""
_backend = CDLL(_backend_binding_lib_path)
_decompile = _backend.decompile
_decompile.argtypes = [
    c_char_p,
    c_size_t,
    c_char_p,
    POINTER(c_size_t),
]
_decompile.restype = c_int


def decompile(compiled: str):
    out_size = c_size_t(0)

    # determine the output buffer size
    ec = _decompile(
        compiled.encode('utf-8'),
        len(compiled),
        c_char_p(0),
        byref(out_size),
    )

    if ec == 0:
        if out_size.value > 0:
            out_size = c_size_t(int(out_size.value) + 1)
            out_str = create_string_buffer(out_size.value)

            # now decompile with enough allocated output buffer
            ec = _decompile(
                compiled.encode('utf-8'),
                len(compiled),
                out_str,
                byref(out_size),
            )

            if ec != 0:
                raise Exception(f'decompile() failed with code: {ec}')

            return out_str.value.decode('utf-8')
        return ''

    raise Exception(f'decompile() failed with code: {ec}')


if __name__ == '__main__':
    print(
        decompile("@JSXBIN@ES@2.0@MyBbyBn0ABJAnABXzBjBBfjzGjHjMjPjCjBjMCfEjzGiTjUjSjJjOjHDfRBFctffnf0DzAEByB")
    )
