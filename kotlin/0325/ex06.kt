fun main(args: Array<String>) {
    val score:Int = 86
    val grade = when(score){
        100 -> "perfect"
        in 80..99 -> "A"
        in 50..79 ->"B"
        else ->"F"
    }
    println(grade)
}