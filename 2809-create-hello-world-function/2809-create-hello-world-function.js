/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
       return  print() ; 
    }
};
function print(){
    let ch = "Hello World" 
    return ch ; 
}

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */