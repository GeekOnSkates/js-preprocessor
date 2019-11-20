// TO-DO: Now it handles "includes within includes"
// but that broke includes inside strings (which users shouldn't do,
// but they might.  Also, includes in comments

#include "./tests.js"

#define TEST 123;

function main() {
	console.log(TEST);
}
