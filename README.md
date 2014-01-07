Chess Puzzles
=============

The plan is to build some fun chess mini games and puzzles in a C/C++ library, make it playable with a proof-of-concept console app, then port it to iOS as a [Sprite Kit](https://developer.apple.com/library/ios/documentation/GraphicsAnimation/Conceptual/SpriteKit_PG/Introduction/Introduction.html) app.

I wouldn't expect this to move quickly - this is just a fun hobby project.


Compiling and Testing
=====================

As of right now, this is an [XCode 5](https://developer.apple.com/technologies/tools/) project. 

All game logic will be included in the ChessPuzzlesLibrary. I plan on writing as many of the tests as possible with [googletest](https://code.google.com/p/googletest/). There are two options to run these tests: as a normal test run in XCode, or by running the "standalone" console target.

Acknowledgements
================

Thanks to [Matt Stevens](https://twitter.com/mattstevens) for his [sample project](https://github.com/mattstevens/xcode-googletest) to get me started with googletest in XCode.
