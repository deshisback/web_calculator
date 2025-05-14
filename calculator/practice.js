const digits = document.getElementById("digits-input")
const digitTypeBtn = document.getElementById("form-button")
const calculateBtn = document.getElementById("calculate")
const output = document.getElementById("digits-output")
const operationsText = document.querySelector("#operations-text")

renderForm = (type) => {
    switch(type){
        case "2":
            digits.innerHTML = `<img src="images/geometric.png"><br>
                                   r1 = <input type="text" id="r1" size="3px" class="correct"> phi1 = <input type="text" id="phi1" size="3px" class="correct"><br>
                                   r2 = <input type="text" id="r2" size="3px" class="correct"> phi2 = <input type="text" id="phi2" size="3px" class="correct">`
            break
        default:
            digits.innerHTML = `<img src="images/algebraic.png"><br>
                                   a1 = <input type="text" id="a1" size="3px" class="correct"> b1 = <input type="text" id="b1" size="3px" class="correct"><br>
                                   a2 = <input type="text" id="a2" size="3px" class="correct"> b2 = <input type="text" id="b2" size="3px" class="correct">`
            break
    }
    for (const input of document.querySelectorAll("[type='text']")){
        input.addEventListener("click", () => setInputsCorrect(document.querySelectorAll("[type='text']")))
    }
}

//для вычисления нужна форма задания числа, сами значения чисел, значения чекбоксов, чтобы вывести только нужную информацию и все
calculateAlgebraic = (type, a1, b1, a2, b2) => {
    nums = [a1, a2, b1, b2]

    for (num of nums){
        if (isNaN(parseFloat(num)) || !isFinite(num)) {
            return ""
        }
    }

    a1 = parseFloat(a1)
    b1 = parseFloat(b1)
    a2 = parseFloat(a2)
    b2 = parseFloat(b2)

    switch(type){
        case "multiplication":
            newa = a1 * a2 - b1 * b2
            newb = b1 * a2 + a1 * b2
            return `z1 * z2 = ${newa} + ${newb}i<br>`
        case "division":
            if (!a2 && !b2){
                return []
            }
            newa = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2)
            newb = (b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2)
            return `z1 / z2 = ${Math.round(newa * 10) / 10} + ${Math.round(newb * 10) / 10}i<br>`
        case "sum":
            newa = a1 + a2
            newb = b1 + b2
            return `z1 + z2 = ${newa} + ${newb}i<br>`
        case "difference":
            newa = a1 - a2
            newb = b1 - b2
            return `z1 - z2 = ${newa} + ${newb}i<br>`
    }
}

geometricToAlgebraic = (type, r1, phi1, r2, phi2) => {

    nums = [r1, r2, phi1, phi2]

    for (num of nums){
        if (isNaN(parseFloat(num)) || !isFinite(num)) {
            return []
        }
    }

    r1 = parseFloat(r1)
    phi1 = parseFloat(phi1)
    r2 = parseFloat(r2)
    phi2 = parseFloat(phi2)

    a1 = r1 * Math.cos(phi1 * Math.PI / 180)
    a2 = r2 * Math.cos(phi2 * Math.PI / 180)

    b1 = r1 * Math.sin(phi1 * Math.PI / 180)
    b2 = r2 * Math.sin(phi2 * Math.PI / 180)

    switch(type){
        case "multiplication":
            newa = a1 * a2 - b1 * b2
            newb = b1 * a2 + a1 * b2
            return [newa, newb]
        case "division":
            if (!a2 && !b2){
                return []
            }
            newa = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2)
            newb = (b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2)
            return [newa, newb]
        case "sum":
            newa = a1 + a2
            newb = b1 + b2
            return [newa, newb]
        case "difference":
            newa = a1 - a2
            newb = b1 - b2
            return [newa, newb]
    }
}

calculateGeometric = (type, r1, phi1, r2, phi2) => {
    nums = geometricToAlgebraic(type, r1, phi1, r2, phi2)

    if (nums.length == 2){
        r = Math.sqrt(nums[0] * nums[0] + nums[1] * nums[1])
        r = Math.round(r * 10) / 10
        phi = Math.atan(nums[1] / nums[0] * Math.PI / 180)
        phi = Math.round(phi * 10) / 10

        return `${r}(cos${phi} + isin(${phi}))`
    }
    return ""
}

setInputsCorrect = (inputs) => {
    for (const input of inputs)
    {
        input.className = "correct"
    }
}

setInputsWrong = (inputs) => {
    for (const input of inputs){
        input.className = "wrong"
    }
}

setOperationsTextCorrect = () => {
    operationsText.className = "operations-correct"
}

setOperationsTextWrong = () => {
    operationsText.className = "operations-wrong"
}

calculator = () => {

    output.innerHTML = ""

    type = document.querySelector('input[name="choose-form"]:checked')?.value
    checkBoxes = document.querySelectorAll("[type='checkbox']")

    i = 0

    for (const box of checkBoxes){
        if (!box.checked) i++
        if (i == 4){
            setOperationsTextWrong()
            return
        }
    }

    const inputs = document.querySelectorAll("[type='text']")

    if (type === "1"){
        a1 = document.getElementById("a1").value
        a2 = document.getElementById("a2").value
        b1 = document.getElementById("b1").value
        b2 = document.getElementById("b2").value

        for (box of checkBoxes){
            if (box.checked){
                str = calculateAlgebraic(box.value, a1, b1, a2, b2)
                if (str == "") {
                    output.innerHTML += `Деление на ноль невозможно<br>`
                }
                output.innerHTML += str
            }
        }
        setInputsCorrect(inputs)
    } else {
        r1 = document.getElementById("r1").value
        r2 = document.getElementById("r2").value
        phi1 = document.getElementById("phi1").value
        phi2 = document.getElementById("phi2").value        

        for (box of checkBoxes){
            if (box.checked){
                str = calculateGeometric(box.value, r1, phi1, r2, phi2) + "<br>"
                if (str == "<br>"){
                    setInputsWrong(inputs)
                    return
                }
                output.innerHTML += str
            }
        }
        setInputsCorrect(inputs)
    }
}

digitTypeBtn.addEventListener("click", () => renderForm(document.querySelector('input[name="choose-form"]:checked')?.value))
calculateBtn.addEventListener("click", calculator)
for (const input of document.querySelectorAll("[type='text']")){
    input.addEventListener("click", () => setInputsCorrect(document.querySelectorAll("[type='text']")))
}
for (const box of document.querySelectorAll("[type='checkbox']")){
    box.addEventListener("click", setOperationsTextCorrect)
}