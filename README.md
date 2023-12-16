# Spell Checker

This program, `speller`, is a simple spell-checker implemented in C. It checks a given text file against a specified dictionary to identify and print misspelled words. The spell-checking process involves loading a dictionary, reading the text file, and comparing each word against the loaded dictionary. The program provides benchmarking information, including the time taken for loading the dictionary, checking the words, determining the dictionary's size, and unloading the dictionary.

## Usage

```bash
./speller [DICTIONARY] text
```

- `DICTIONARY`: Optional parameter specifying the dictionary file to use (default is "dictionaries/large").
- `text`: The text file to spell-check.

## Implementation Details

### Dictionary Loading

The program loads a dictionary using the `load` function from the provided `dictionary.h` header file. The dictionary file path is determined based on the command-line arguments.

### Spell Checking

The text file is opened, and each word is extracted and checked against the loaded dictionary. Words with numbers or strings exceeding a certain length are ignored. The program reports misspelled words along with benchmarking information.

### Benchmarking

The program measures the time taken for various operations, such as loading the dictionary, checking words, determining dictionary size, and unloading the dictionary. These benchmarks are printed at the end of the spell-checking process.

## Benchmark Metrics

- **WORDS MISSPELLED:** Number of misspelled words found in the text.
- **WORDS IN DICTIONARY:** Number of words in the loaded dictionary.
- **WORDS IN TEXT:** Total number of words in the input text file.
- **TIME IN load:** Time taken to load the dictionary.
- **TIME IN check:** Time taken to check the words in the text.
- **TIME IN size:** Time taken to determine the dictionary's size.
- **TIME IN unload:** Time taken to unload the dictionary.
- **TIME IN TOTAL:** Total time taken for all operations.

## Error Handling

The program includes basic error handling for cases where the dictionary or text file cannot be loaded or read. It prints relevant error messages to the console.

## Compilation

To compile the program, ensure that the `dictionary.c` and `dictionary.h` files are included in the compilation. For example:

```bash
gcc -o speller speller.c dictionary.c -lm
```

## Credits

This spell-checker implementation is based on the coursework from Harvard University's CS50 course.

## License

This program is distributed under the [MIT License](LICENSE). See the LICENSE file for details.
