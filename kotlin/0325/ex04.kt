fun main(args: Array<String>) {
    val name = "0마드리길"
    var healthPoints = 89
    val isBlessed = true
    val isImmortal = false
// 아우라
    val auraVisible = isBlessed && healthPoints > 50 || isImmortal
    val auraColor = if(auraVisible) "GREEN" else "NONE"
    println(auraColor)
    val healthStatus = if(healthPoints == 100) "최상의 상태임!"
    else if (healthPoints >= 90) "1약간의 찰과상만 있음."
    else if (healthPoints >= 75)
        if(isBlessed) "2경미한 상처가 있지만 빨리 치유됨!"
        else "3경미한 상처만 있음."
    else if (healthPoints >= 15) "4많이 다친 것 같음"
    else "5최악의 상태임!"
// 플레이어의 상태 출력
    println(name + " " + healthStatus)
}
