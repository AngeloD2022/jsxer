# Jsxer
A faster decompiler for Adobe's (Legacy) ExtendScript binary format (*.jsxbin).

> [!WARNING]
> This project is currently being rewritten in Rust. Development is occurring on the `rust-rewrite` branch.

## Features
* [x] Lifts JSXBIN back to JavaScript code.
* [x] Jsxblind deobfuscation (experimental).
* [x] Python bindings.
* [x] Dynamic library.
* [x] **Fast as hell.**

## What is ExtendScript?
ExtendScript is a scripting language and an associated toolkit developed by Adobe Systems, intended for use with Creative Suite and Technical Communication Suite products. It is a dialect of the ECMAScript 3 standard and therefore similar to JavaScript and ActionScript. The toolkit comes bundled with Creative Suite and Technical Communication Suite editions and can access tools within applications like Photoshop, FrameMaker, InDesign or After Effects for batch-processing projects.

## Please, do not use this project unethically.

#### yo, pirates, hear me out...

Look, I get that it's tempting– money doesn't grow on trees.

Many script authors are independent developers, and by stealing their work you make what they do unsustainable and their lives harder. Without income, they are not able to create and maintain what many people may depend on.  

Jsxer (in addition to simply being a fun and educational project to develop) was made for source code recovery and security research purposes. It is free and open-source software– and as such, I won't try to control what you can and can't do with it. 

Just remember that script authors are real humans! So if you like their work, show some love and fork over the dough. :)

Appreciate ya!

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
jsxer <jsxbin path>
```

The `--unblind` flag enables the experimental deobfuscation.

## Credits
  - Thanks to Andrin Meier ([@andrinpricemeier](https://github.com/andrinpricemeier), formerly `@autoboosh`) for his research on the format, and his project [jsxbin-to-jsx-converter](https://github.com/autoboosh/jsxbin-to-jsx-converter).
  - Thanks to [@codecopy](https://github.com/codecopy) for keeping a [fork](https://github.com/codecopy/jsxbin-to-jsx-converter) of `@autoboosh`'s project, where the original vanished as a consequence of a DMCA takedown from Adobe.


## Contributions
Contributions are welcome. Open an issue if you have a problem. Check contribution guidelines [here](CONTRIBUTING.md).

---

## Star History

[![Star History Chart](https://api.star-history.com/svg?repos=AngeloD2022/jsxer&type=Date)](https://star-history.com/#AngeloD2022/jsxer&Date)

