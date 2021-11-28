
from distutils.core import setup, Extension
module = Extension(
    "cppset",
    sources=["set_wrapper.cpp"],
    extra_compile_args=["-O3", "-march=native"]
)
setup(
    name="SetMethod",
    version="0.1.0",
    description="wrapper for C++ set",
    ext_modules=[module]
)
