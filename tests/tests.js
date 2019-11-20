#include "./include-example.js"
#include "./another-example.js"

// Tests if "#includes" inside strings get copied over (they shouldn't)
// Whoops!  Guess I'll have to check for includes in comments too!
function test1() {
	example("Boom!", "See?  It worked!");
	example("Will this break?", "#include maybe");
	example("What about tweets?", "#whatageek");
	example("Those didn't break, what about this?", '#include "./include-example.js"');
	example("Or this?", '\'#include "./include-example.js"');
}
