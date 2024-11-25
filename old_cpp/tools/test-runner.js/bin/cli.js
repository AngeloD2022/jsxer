#!/usr/bin/env node

const convertScripts = require('jsxbin/src/convertScripts');

const args = process.argv;

if (args.length >= 4) {
    const input = args[2];
    const output = args[3];

    convertScripts([input], [output]);
} else {
    console.error('expected args: 4, supplied: ' + args.length);
    process.exit(1);
}