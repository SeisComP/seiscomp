# Contributing to SeisComP

Thanks for your interest in contributing to SeisComP.

## Contributor License Agreement

Your contribution will be under the license of the corresponding repository as per [GitHub's terms of service](https://help.github.com/articles/github-terms-of-service/#6-contributions-under-repository-license).

We will ask you to sign a CLA prior to accepting your contribution.

## GIT commit messages

For GIT commits please follow this rules:

1. Use the imperative mood in the subject line.
   Use "Fix", "Change", "Add" instead of "Fixed", "Changed"
   or "Added".
2. Always leave the second line blank.
3. Do not end the summary line with a period, it's a title
   and they don't end with a period.
4. Capitalize the subject line. Use "Fix bug in ..." instead of
   "fix bug in ...".
5. Use the body to explain what and why rather than how.
6. Prefix the title with the scope of changes enclosed in square
   brackets. This helps us to already identify the location of
   changes in the code tree just by inspecting the message title.
   Example: "[proc] Fix typo". Scopes can be formed from application
   names, e.g. "scolv" or library names, e.g. "core".

## Code quality

1. Please follow our [coding style](doc/base/coding-conventions.rst).
2. Make sure that the code you want to be pulled compiles at your
   development system flawlessly.
3. Please keep also in mind that we target at least Debian and CentOS
   in their last two major versions and your code will have to compile
   there as well.
4. Add documentation for new classes and their methods. Furthermore
   document code sections which are not easy to understand or heavily
   optimized.
5. Add application documentation when you change commandline options,
   configuration or just semantics. Or simply keep the documentation
   with the code in sync.

Feel free to get in touch with us through Github issues to ask
questions about how to implement a specific feature or to learn
about the existing codes and their structure.

## New applications

When you want to add a new application to any repository, please provide
in addition to the code a

* default configuration file
* RST documentation
* XML description

## Documentation

1. Follow our [documentation style](doc/base/style-guide.rst).

We appreciate your contributions and we are looking forward to starting
discussions about new features and existing workflows.
