# JavaScript Preprocessor

## The Problems

### 1. No way to include JS code from within JS code

It's funny how most developers (myself included) prefer to avoid using a ton of &lt;script&gt; tags to add more code to their website or web app.  I don't know if there's an actual reason (like a performance drawback) or if it's just us, but it's totally a thing.  I've seen all kinds of ways to do it, and none of them are great IMO.  Like Dojo does this:

```js
require([
	"module/to/include"
], function(myModule){
	// code
});```

And Node copied the "import" keyword from Python/Java, which is good for them (lol), but not possible for web apps (yet?).  It's also a bit more complex than in languages like Python or C, though of course that could just be my limited experience talking.  And of course, the default way is a ton of &lt;script&gt; tags - which will always have its place IMO (otherwise you could be dumping a megabyte or two on users when the page loads).  But it's still not helpful for our development workflow, cuz we all seem to want a better way.

### 2. Unnecessary code that just adds bloat

For keyboard events, I've often seen (and wrote) crap like this:

```js
const Keys = {
	LEFT: 37, RIGHT: 39, UP, 38, DOWN: 40, SPACE: 32,
	// etc.
}```

Similarly, I find I use constants that are not part of the language.  Constants are a useful tool, but they can add unnecessary bytes to the download size too.  For example, let's say I have code like this:

```js
const APPLES = 1;
const ORANGED = 2;
const BANANAS = 4;
const GRAPES = 8;

makeFruitSalad(APPLES | ORANGES | BANANAS | GRAPES);```

Wouldn't the code be lighter if we just did:

```js
makeFruitSalad(1 | 2 | 4 | 8); // or even just "15"?```

This simple change saves 5 lines of code and 5-6 bytes per parameter.  And this is just a stupid demo - in a real program, anytime constants are used, we could be making our code a lot lighter.

### 3. Constantly minifying, or tinkering with complicated build tools

We all know JSMin, the awesome C program that lightens up our JS, but we would have to run it on every file, or do a bunch of copy/pasting and then minify it.  It's an important step, but it's a pain in the bits! Of course all the heavy-duty frameworks have way-too-complicated build tools, with a mountain of config files and a bazillion-and-one settings. On the positive side, some of the better language-x-to-JavaScript compilers will do some of this for you, but they're trying to reinvent the wheel.  I'm not trying to reinvent or replace JavaScript... I just want a tool that adds certain features I (and apparently many others) wish it had.

## My solution: a JavaScript preprocessor

If you've ever dabbled in C or C++, you've probably heard that word
before.  A "preprocessor" is a tool that runs before the compiler.  It
looks for lines starting with #include or #define, and does some clever
copy-&-pasting before the compiler does its thing.  Of course there's no
compiler in JavaScript, but I think a preprocessor would still be a big
help.  If done correctly, it could solve a lot of problems without
introducing any new ones.

## Documentation - comin' when it's workin'. :)
