#!/usr/bin/node
/*
    Print a square of size N using '#'
*/

if (process.argv.length <= 2) {
    process.stderr.write("Missing argument\n");
    process.exit(1);
}

// Parse in base 10 (decimal)
let size = parseInt(process.argv[2], 10);

if (isNaN(size)) {
    process.stderr.write("Missing argument\n");
    process.exit(1);
}

for (let i = 0; i < size; i++) {
    for (let j = 0; j < size; j++) {
        process.stdout.write("#");
    }
    process.stdout.write("\n"); // Add newline at the end of each row
}
