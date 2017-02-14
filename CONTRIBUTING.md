[Software](#software)    
[Style Guidelines](#style-guidelines)  
[Best Practices for Contributing](#best-practices-for-contributing)

These document outlines the different guidelines for contributing to this repository.

## Software
Frosty Engine is compiled using MSVC under C++ 14. Ensure that you are compiling under C++ 14 using the MSVC compiler.

## Style Guidelines

TODO

## Best Practices for Contributing
[Best Practices for Contributing]: #best-practices-for-contributing
* Pull Requests represent final code. Please ensure they are:

    * Well tested by the author. It is the author's job to ensure their code works as expected.
    * Be free of unnecessary log calls. Logging is great for debugging, but when a pull request is made, log calls should only be present when there is an actual error or to warn of an unimplemented feature.

* If your code is untested, log heavy, or incomplete, prefix your pull request with "[WIP]", so others know it is still being tested and shouldn't be considered for merging yet.

* Small changes are preferable over large ones. The larger a change is the more likely it is to conflict with the project and thus be denied. If your addition is large, be sure to extensively discuss it in an "issue" before you submit a pull request, or even start coding.

* Document your changes in your pull request. If you add a feature that you expect others to use, explain exactly how future code should interact with your additions.

* Avoid making changes to more files than necessary for your feature (i.e. refrain from combining your "real" pull request with incidental bug fixes). This will simplify the merging process and make your changes clearer.

* Include screenshots demonstrating your change if applicable. All graphical changes should include screenshots.

That's it! Following these guidelines will ensure that your additions are approved quickly and integrated into Frosty Engine.

