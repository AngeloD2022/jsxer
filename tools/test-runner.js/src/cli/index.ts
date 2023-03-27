#!/usr/bin/env node

const fs = require('node:fs');
const esc = require('es-compile');

const args = process.argv;

if (args.length >= 2) {
    const input = args[0];
    const output = args[1];

    const contents = fs.readFileSync(input);

    const result = esc.compileToJSXBIN(contents);

    if (result.code === 0) {
        fs.writeFileSync(output, result.output);
    } else {
        console.error(result.error);
        process.exit(result.code);
    }
} else {
    console.error('expected args: 2, supplied: ' + args.length);
    process.exit(1);
}