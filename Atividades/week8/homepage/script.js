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