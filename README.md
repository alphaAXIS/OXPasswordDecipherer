# OX Password Decipherer 1.3.8-β

## I. Introduction

The ***\*OX Password Decipherer\**** is a custom-built tool designed to decrypt passwords encrypted with the unique ***\*OX Password\**** encryption scheme, invented by the same author. This tool utilizes a complex system of key mappings, based on a novel application of arithmetic operations, to transform encrypted messages back into their original plaintext form.

## II. Version

- ***\*Version\****: 1.3.8-beta

## III. Key Features

- **Custom Key Mapping**: Uses a hardcoded key mapping to decrypt encrypted text.
- **Versatile Use**: Can decrypt text encrypted with the specific key mapping provided.
- **Easy to Use**: Simple input-output interface for decryption.

## IV. Installation

### 1. If you have a programming locale

#### Prerequisites

​    a. A programming environment that supports the language in which the decipherer is written (C++).<br>    b. (Optional) Any dependencies required by the decipherer's source code.

#### Instructions

​    a. Download the source code of the decipherer from the [GitHub repository](https://github.com/alphaAXIS/OXPasswordDecipherer/).<br>    b. Extract the source code to a directory of your choice.<br>    c. Open a terminal or command prompt and navigate to the directory containing the decipherer's source code.<br>    d. Follow any additional installation instructions specific to the decipherer (e.g., installing dependencies).<br>    e. Compile and/or run the decipherer according to the programming language's conventions.

### 2. If you do not have a programming locale

#### Instructions

​    a. Download the executable file of the decipherer from the [GitHub repository](https://github.com/alphaAXIS/OXPasswordDecipherer/).<br>    b. Add the directory of this executable file to "Path".<br>    c. Then you can easily use it when opening "oxpd.exe" or inputting "oxpd" in the cmd. 

## V. Key Mappings

The decipherer employs a set of predefined key mappings to translate encrypted symbols into their corresponding characters. Here's an overview of the key mappings:

- `OX` → `a`
- `OOX` → `b`
- `OXX` → `c`
- `OOXX` → `d`
- `--O-OX--XX` → `e`
- `OO--X-OX--` → `f`
- `--O-OX----X-OX--` → `g`
- `OO--X-OOX--` → `h`
- `O--X-OXX--` → `i`
- `OO--X-OXX--` → `j`
- `O--X-OOXX--` → `k`
- `OO--X-OOXX--` → `l`
- `O--X-----O-OX--XX----` → `m`
- `OO--X-----O-OX--XX----` → `n`
- `O` → `o`
- `OO--X---OO--X-OX------` → `p`
- `O--X-----O-OX----X-OX------` → `q`
- `OO--X-----O-OX----X-OX------` → `r`
- `O--X---OO--X-OOX------` → `s`
- `OO--X---OO--X-OOX------` → `t`
- `O--X---O--X-OXX------` → `u`
- `OO--X---O--X-OXX------` → `v`
- `O--X---OO--X-OXX------` → `w`
- `X` → `x`
- `O--X---O--X-OOXX------` → `y`
- `OO--X---O--X-OOXX------` → `z`
- `||` → `0`
- `|O|` → `1`
- `|X|` → `2`
- `|OX|` → `3`
- `|OOX|` → `4`
- `|OXX|` → `5`
- `|OOXX|` → `6`
- `|--O-OX--XX|` → `7`
- `|OO--X-OX--|` → `8`
- `|--O-OX----X-OX--|` → `9`
- `=O--X---OO--X-----O-OX--XX--------=` → `!`
- `=OO--X---OO--X---OO--X-OOX----------=` → `,`
- `=OO--X---O--X---O--X-OXX----------=` → `.`

For uppercase letters, we add the character '+' to the ends of the password corresponding to lowercase letters. For example, `+OX+` → `A`, `+OO--X---O--X-OOXX------+` → `Z`

## VI. Principle

The decryption process leverages a unique system of arithmetic operations that act as the cornerstone of the decryption algorithm. These operations are applied to the encrypted input, transforming it into the corresponding plaintext output using the aforementioned key mappings.

We set $O=1$, $X=2$, $A=3$, $B=4$, and so on. And then use O and X to represent all English letters, and two letters together indicate addition, while a "-" indicates multiplication. The “--” can represent a left or right parenthesis. This is the principle of this password to a certain extent. The actual principle may be more complex than this, and we do not need to elaborate on it here.

## VII. Usage

This tool is available for Windows. On Windows, press the Windows logo key+R, enter "cmd" to open the command prompt, and then type "oxpd" to access the tool. If the command prompt indicates "'oxpd' is not an internal or external command, nor a runnable program or batch file.", you should add the location of the "bin" directory from the tool to the "Path" system variable.

## VIII. Disclaimer

This tool is intended for educational and research purposes only. Unauthorized use to decrypt passwords or other sensitive information may violate privacy and security laws. Always ensure that you have the proper authorization before using this tool.

## IX. Contributions & Feedback

We welcome contributions, suggestions for improvement, and bug reports. You can reach us via:

- Email: [alphaAXIS2018@outlook.com](mailto:alphaAXIS2018@outlook.com)
- GitHub Issues: [github.com/alphaAXIS/OXPasswordDecipherer](https://github.com/alphaAXIS/OXPasswordDecipherer)

## X. License

This tool is licensed under the GPL-3.0 License. See the [LICENSE](https://www.gnu.org/licenses/gpl-3.0.en.html https://chat.baidu.com/LICENSE) file for more details.

## XI. Contact Information

For any questions, feedback, or collaboration opportunities, please feel free to reach out to the author via email or through their professional network.

- **Author**: Stanley Williams (Founder & CEO of alphaAXIS, Inc.)
- **Email**: [alphaAXIS2018@outlook.com](mailto:alphaAXIS2018@outlook.com)
- **GitHub**: [github.com/alphaAXIS/](https://github.com/alphaAXIS/)
