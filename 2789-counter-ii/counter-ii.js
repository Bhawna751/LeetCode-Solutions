/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let present = init;
    function increment(){
        return ++present;
    }
    function decrement(){
        return --present;
    }
    function reset(){
        return (present = init);
    }
    return  {increment,decrement,reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */