/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = (s) => s.split(" ").map(item => item.split("").reverse().join("")).join(" ")