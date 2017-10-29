function _makeAlphabet() {
    const lower = 97;
    const upper = 122;

    return Array.apply(null, {length: upper - lower + 1}).map(
        Function.call,
        i => String.fromCharCode(i + lower)
    ).filter(_isAlpha).join('');
}

function _isAlpha(letter) {
    return /[a-zA-Z]/.test(letter);
}

function caesar(plain, shift) {
    const alphabet = _makeAlphabet();

    return plain.split('').reduce((acc, letter) => {
        if (!_isAlpha(letter)) {
            return acc + letter;
        }

        const letterLower = letter.toLowerCase();
        const idx = alphabet.indexOf(letterLower);
        let newIdx = idx + shift % (alphabet.length - 1);

        if (newIdx < 0) {
            newIdx = alphabet.length + newIdx
        }

        if (newIdx >= alphabet.length) {
            newIdx = 0
        }

        const newLetter = alphabet[newIdx];
        return acc + (letter === letterLower ? newLetter : newLetter.toUpperCase());
    }, '');
}


console.assert(caesar('AzaZ', shift=1), 'BabA')
console.assert(caesar('AzaZ', shift=-1), 'ZyzY')
console.assert(caesar('This is a caesar cipher example', shift=0) === 'This is a caesar cipher example')
console.assert(caesar('A not so long string', shift=2) == 'C pqv uq nqpi uvtkpi')
console.assert(caesar('Negative shift', shift=-1) == 'Mdfzshud rghes')
