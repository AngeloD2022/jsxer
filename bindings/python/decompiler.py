import os
import platform
from ctypes import CDLL, POINTER, \
    c_int, c_char_p, c_size_t, c_bool, byref, create_string_buffer


pf = platform.system()

if pf == 'Windows':
    _backend_binding_lib_path = '../../bin/debug/dll/lib-jsxer.dll'
elif pf == 'Linux':
    _backend_binding_lib_path = '../../bin/debug/dll/lib-jsxer.so'
elif pf == 'Darwin':
    _backend_binding_lib_path = '../../bin/debug/dll/lib-jsxer.dylib'
else:
    raise EnvironmentError(f'Unknown platform: {pf}')

_backend_binding_lib_path = os.path.realpath(_backend_binding_lib_path)

if not os.path.isfile(_backend_binding_lib_path):
    raise FileNotFoundError(f'Backend lib not exists in place: {_backend_binding_lib_path}')

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
    c_bool
]
_decompile.restype = c_int


def decompile(compiled: str, jsxblind_deobfuscate=False):
    out_size = c_size_t(0)

    # determine the output buffer size
    ec = _decompile(
        compiled.encode('utf-8'),
        len(compiled),
        c_char_p(0),
        byref(out_size),
        c_bool(jsxblind_deobfuscate)
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
                c_bool(jsxblind_deobfuscate)
            )

            if ec != 0:
                raise Exception(f'decompile() failed with code: {ec}')

            return out_str.value.decode('utf-8')
        return ''

    raise Exception(f'decompile() failed with code: {ec}')


if __name__ == '__main__':
    print(
        decompile("""@JSXBIN@ES@2.0@MyBbyBn0ACJAnABjzBjYBfneB2nfnffJBnAEXzIjUjPiTjUjSjJjOjHCfEXzKjDjI
jBjSiDjPjEjFiBjUDfjBfRBFdAffRBFdQff0DzAEByB""")
    )
