fun main(args: Array<String>) {
    val name = "name"
    var healthPoints = 89
    val isBlessed = true
    val isImmortal = false
// 아우라
    val auraVisible = isBlessed && healthPoints > 50 || isImmortal
    val auraColor = if(auraVisible) "GREEN" else "NONE"
    println(auraColor)
    val healthStatus = when(healthPoints) {
        100 -> "1최상의 상태임!"
        in 90..99 -> "2약간의 찰과상만 있음."
        in 75..89 -> if (isBlessed) "3경미한 상처가 있지만 빨리 치유됨!"
        else "4경미한 상처만 있음."
        in 15..74 -> "5많이 다친 것 같음"
        else -> "6최악의 상태임!"
    }
// 플레이어의 상태 출력
    println(name + " " + healthStatus)
}