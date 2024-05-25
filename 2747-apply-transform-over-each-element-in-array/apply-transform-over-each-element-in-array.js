/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const transArr = [];
    for(let i=0;i<arr.length;i++){
        transArr[i] = fn(arr[i],i);
    }
    return transArr;
};