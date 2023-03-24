import esc from 'es-compile'

export function compileToJSXBIN(source: string) {
    const result = esc.compile(source);

    if (result.code !== 0) {
        throw SyntaxError(result.error);
    }

    return result.output;
}