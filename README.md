# bar-menu

`bar-menu` is a terminal emulator based menu, which may be used as an alternative to dmenu in the future. Currently, many features are still missing.

## But why?

I tried [term-dmenu](https://github.com/seirdy/term-dmenu) by Seirdy, but I could not figure out how to make it work (or I am too lazy to do that); Therefore I built my own thing. Also, this is an example how my library [BarnabasBox](https://github.com/nmke-de/BarnabasBox) can be used.

## What does the name `bar-menu` mean?

"bar" stands for BarnabasBox, a library used for this program. The menu part should be apparent.

## Dependencies

- [BarnabasBox](https://github.com/nmke-de/BarnabasBox) (duh)
	- Dependencies of BarnabasBox

## Build

Type `make` if you have make installed. Please note that the default is static linking. Edit the Makefile to suit your needs.

If you do not have `make` installed, you can refer to the commands in the Makefile to compile the program.

## Usage

```bash
bar-menu list of items to display
```

So far, `bar-menu` does not support piping.

To navigate between the options, use `j` and `k`. Pressing the `Return` key prints the selected option to stdout and exits the program.
Pressing `/` opens a prompt to filter the given entries with a substring or to use a custom option.
One can quit the program without generating output by pressing `q` or the Escape key.

