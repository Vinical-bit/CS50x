function resetButtons() {
    document.querySelectorAll('.choice button').forEach(function(btn) {
        btn.style.cssText = ''  // volta ao estilo original do CSS
    })
}


function correctAnswer() {
    resetButtons()
    let bee = document.querySelector('#bee')
    let fdbck1 = document.querySelector('#feedback1')
    
    bee.style.backgroundColor = 'green'
    bee.style.color = 'black'
    bee.style.fontSize = '20px'
    bee.style.fontWeight = 'bold'
    bee.style.textAlign = 'center'
    bee.style.padding = '10px'
    bee.style.borderRadius = '5px'
    bee.style.boxShadow = '0 0 10px rgba(0, 0, 0, 0.5)'
    
    fdbck1.textContent = 'Correct!'
}
document.querySelectorAll('.wr').forEach(function(wr) {
    wr.addEventListener('click', function wrongAnswer() {
        resetButtons()
        wr.style.backgroundColor = 'red'
        wr.style.color = 'white'
        wr.style.fontSize = '20px'
        wr.style.fontWeight = 'bold'
        wr.style.textAlign = 'center'
        wr.style.padding = '10px'
        wr.style.borderRadius = '5px'
        wr.style.boxShadow = '0 0 10px rgba(0, 0, 0, 0.5)'
        let fdbck1 = document.querySelector('#feedback1')
        fdbck1.textContent = 'Incorrect!'
    })})
    
    function checkAnswer() {
        let check = document.querySelector('#answer').value
        
        if (check.toLowerCase() == "blue whale"){
            
            let fdbck2 = document.querySelector('#feedback2')
            fdbck2.textContent = 'Correct!'

            document.querySelector('#answer').style.backgroundColor = 'green'
        }
        else{
            let fdbck2 = document.querySelector('#feedback2')
            fdbck2.textContent = 'Incorrect!'

            document.querySelector('#answer').style.backgroundColor = 'red'
        }
}

