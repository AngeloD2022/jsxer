"""
Python Bindings for JSXBIN decompiler
Written by Angelo DeLuca
Licensed under BSD-3-Clause
"""

import ctypes

# replace the below string with the path to the built python bindings (target jd_pybind in cmake)
PATH_TO_PYBIND_BINARY = 'cmake-build-debug/libjd_pybind.dylib'


class jsxd_result(ctypes.Structure):
    """
    struct jsxd_result {
        char* data;
        unsigned long length;
    };
    """

    _fields_ = [
        ('data', ctypes.POINTER(ctypes.c_char)),
        ('length', ctypes.c_ulong)
    ]


NATIVE_DECOMPILER = ctypes.CDLL(PATH_TO_PYBIND_BINARY)
decompile_native_func = NATIVE_DECOMPILER.decompile_jsxbin
decompile_native_func.restype = jsxd_result


def decompile(fileContents: str):
    result = decompile_native_func(fileContents.encode('utf-8'))
    data = result.data

    decompiled: bytes = data[:result.length]
    return decompiled.decode('utf-8')
