import { defineConfig } from 'tsup'
import fs from 'node:fs'
import path from 'node:path'

export default defineConfig((options) => {
    return {
        minify: !options.watch,
        entry: {
            index: 'src/index.ts',
            cli: 'src/cli/index.ts',
        },
        platform: 'node',
        format: 'cjs',
        splitting: false,
        sourcemap: true,
        clean: true,
        dts: true,
        onSuccess: async () => {
            const cliPath = path.join(__dirname, 'dist', 'cli.js');
            const binPath = path.join(__dirname, 'bin');
            const cliDstPath = path.join(binPath, 'cli.js');

            fs.mkdirSync(binPath, { recursive: true });
            fs.copyFileSync(cliPath, cliDstPath);
        },
    }
})