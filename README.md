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

Makefile incoming.

## Usage

```bash
bar-menu list of items to display
```

So far, `bar-menu` does not support piping.

To navigate between the options, use `j` and `k`. Pressing the `Return` key prints the selected option to stdout and exits the program.

