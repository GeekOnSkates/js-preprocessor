#include "./include-example.js"
#include "./another-example.js"

function main() {
	example("Boom!", "See?  It worked!");
	example("Will this break?", "#include maybe");
	example("What about tweets?", "#whatageek");
	example("Those didn't break, what about this?", '#include "./include-example.js"');
	example("Or this?", '\'#include "./include-example.js"');
}
