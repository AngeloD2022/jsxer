import logging
import platform
from os import path
from ctypes import CDLL, POINTER, c_int, c_char_p, c_size_t, c_bool, byref, create_string_buffer

logger = logging.getLogger(__file__)


def _get_binding_path():
    pf = platform.system().lower()

    for build_type in ('release', 'debug',):
        _binding_base_path = path.realpath(
            path.join(
                path.dirname(__file__),
                '..',
                '..',
                'bin',
                build_type,
                'dll',
            )
        )

        if pf == 'windows':
            _binding_lib_path = path.join(_binding_base_path, 'lib-jsxer.dll')
        elif pf == 'linux':
            _binding_lib_path = path.join(_binding_base_path, 'lib-jsxer.so')
        elif pf == 'darwin':
            _binding_lib_path = path.join(_binding_base_path, 'lib-jsxer.dylib')
        else:
            raise EnvironmentError(f'Unknown platform: {pf}')

        logger.debug(f'Searching for Backend lib at: {_binding_lib_path}')

        if path.isfile(_binding_lib_path):
            logger.debug(f'Backend lib found at: {_binding_lib_path}')
            return _binding_lib_path
    else:
        raise FileNotFoundError(f'Backend lib not found!')


"""
int decompile(const char* input, size_t in_len, char* output, size_t* out_len, bool unblind = false)
"""
_backend = CDLL(_get_binding_path())
_decompile = _backend.decompile
_decompile.argtypes = [
    c_char_p,
    c_size_t,
    c_char_p,
    POINTER(c_size_t),
    c_bool
]
_decompile.restype = c_int


def decompile(compiled: str, unblind=False):
    out_size = c_size_t(0)

    # determine the output buffer size
    ec = _decompile(
        compiled.encode('utf-8'),
        len(compiled),
        c_char_p(0),
        byref(out_size),
        c_bool(unblind)
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
                c_bool(unblind)
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
