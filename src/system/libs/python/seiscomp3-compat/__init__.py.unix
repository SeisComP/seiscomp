import os
import sys
import warnings

sys.setdlopenflags(os.RTLD_LAZY | os.RTLD_GLOBAL)

# Since Python 3.2 DeprecationWarnings are ignored by default. Since Python 3.7
# DeprecationWarnings are shown when triggered directly by code in __main__.
# We enable DeprecationWarnings again unless warning options have been specified on the
# command-line, e.g., -Wignore.
if not sys.warnoptions:
    warnings.simplefilter("default", category=DeprecationWarning)

warnings.warn(
    "The SeisComP3 python API compatibility layer is deprecated and will be removed "
    "with SeisComP 7. Change your imports from 'seiscomp3' to 'seiscomp'.",
    DeprecationWarning,
    2
)
