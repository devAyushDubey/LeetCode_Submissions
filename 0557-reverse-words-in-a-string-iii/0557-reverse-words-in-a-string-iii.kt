class Solution {
    fun reverseWords(s: String) = s.split(" ").map{it -> it.reversed()}.joinToString(" ")
}