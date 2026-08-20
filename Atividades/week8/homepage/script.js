const bioText = document.getElementById('bio-text');
const bioToggle = document.getElementById('bio-toggle');

bioToggle.addEventListener('click', () => {
    bioText.classList.toggle('expanded');

    if (bioText.classList.contains('expanded')) {
        bioToggle.textContent = 'Ler menos';
        bioToggle.setAttribute('aria-expanded', 'true');
    } else {
        bioToggle.textContent = 'Ler mais';
        bioToggle.setAttribute('aria-expanded', 'false');
    }
});

function getWord() {
    let wordValue = document.querySelector('#textoInput').value

    document.querySelector('#textoPreview').textContent = wordValue

    console.log(wordValue)
    console.log(wordValue.length)
    
    document.querySelector('#charCount').textContent = 'CARACTERES: ' + wordValue.length

}