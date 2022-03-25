fun main(args: Array<String>) {
    val name = "마드리길"
    var healthPoints = 89
    val isBlessed = true
    val isImmortal = false
// 아우라
// if(isBlessed && healthPoints > 50 || isImmortal) {
    val auraVisible = isBlessed && healthPoints > 50 || isImmortal
    if(auraVisible) {
        println("GREEN")
    } else {
        println("NONE")
    }
//    :
}