# ExtendScript Decompiler
A faster decompiler for Adobe's (Legacy) ExtendScript binary format (*.jsxbin).

## Features
* [x] Lifts JSXBIN back to JavaScript code.
* [x] Jsxblind deobfuscation (experimental).
* [x] Python bindings.
* [x] Dynamic library.
* [x] **Fast as hell.**

## What is ExtendScript?
ExtendScript is a scripting language and an associated toolkit developed by Adobe Systems, intended for use with Creative Suite and Technical Communication Suite products. It is a dialect of the ECMAScript 3 standard and therefore similar to JavaScript and ActionScript. The toolkit comes bundled with Creative Suite and Technical Communication Suite editions and can access tools within applications like Photoshop, FrameMaker, InDesign or After Effects for batch-processing projects.

## Build (MacOS)

### [Video Tutorial](https://www.youtube.com/watch?v=939Bo5iTxo0)

Open the Terminal app to run the following commands. If you are unfamiliar with Terminal, you can find it in /Applications/Utilities/Terminal.app.

*Install CMake:*
```bash
brew install cmake
```

*Configure and build the project:*
```bash
cmake .
cmake --build . --config release 
```

*After a successful build, navigate to the folder with the executable:*
```bash
cd ./bin/release/
```

## Usage

> **Note**
> Make sure that the input file only contains the JSXBIN literal itself.<sup><a href="https://youtu.be/939Bo5iTxo0?lc=UgyPDxgsuRmbfd8MI-F4AaABAg.9gIEl4rxFVa9gIFW1EPzqO">\[1\]</a></sup>&ensp;(Usually starting with `@JSXBIN@`)

```bash
jsxer <jsxbin path> <output path> [--jsxblind]
```

The `--jsxblind` flag enables the experimental deobfuscation.

## Credits
  - Thanks to Andrin Meier ([@andrinmeier](https://github.com/andrinmeier), formerly `@autoboosh`) for his research on the format, and his project [jsxbin-to-jsx-converter](https://github.com/autoboosh/jsxbin-to-jsx-converter).
  - Thanks to [@codecopy](https://github.com/codecopy) for keeping a [fork](https://github.com/codecopy/jsxbin-to-jsx-converter) of `@autoboosh`'s project, where the original vanished as a consequence of a DMCA takedown from Adobe.


## Contributions
Contributions are welcome. Open an issue if you have a problem. Check contribution guidelines [here](CONTRIBUTING.md).
