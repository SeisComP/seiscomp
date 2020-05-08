import sys
if sys.version_info >= (3,3):
    # Python 3.3 introduced dlopen flags in the os module
    import os
    sys.setdlopenflags(os.RTLD_LAZY | os.RTLD_GLOBAL)
else:
    # The DLFCN modules was removed with Python 3.6
    import DLFCN
    sys.setdlopenflags(DLFCN.RTLD_LAZY | DLFCN.RTLD_GLOBAL)
