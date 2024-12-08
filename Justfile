list:
    just -l

cli-run:
    cargo run --package jsxer_cli --bin jsxer_cli --help

cli-build:
    cargo build --package jsxer_cli --bin jsxer_cli

cli-dev argument:
    ./target/debug/jsxer_cli.exe --help {{argument}}