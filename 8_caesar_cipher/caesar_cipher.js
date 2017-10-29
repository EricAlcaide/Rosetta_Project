function caesar(plain, shift) {
    return plain.split('').reduce((acc, letter) => {
        if (!/[a-zA-Z]/.test(letter)) {
            return acc + letter;
        }

        const letterLower = letter.toLowerCase();
        const idx = letterLower.charCodeAt();
        let newIdx = (idx + shift - 97) % 26;

        if (newIdx < 0) {
            newIdx = 26 + newIdx
        }

        if (newIdx > 25) {
            newIdx = 0
        }

        const newLetter = String.fromCharCode(newIdx + 97);
        return acc + (letter === letterLower ? newLetter : newLetter.toUpperCase());
    }, '');
}


console.assert(caesar('AzaZ', shift=1), 'BabA')
console.assert(caesar('AzaZ', shift=-1), 'ZyzY')
console.assert(caesar('This is a caesar cipher example', shift=0) === 'This is a caesar cipher example')
console.assert(caesar('A not so long string', shift=2) == 'C pqv uq nqpi uvtkpi')
console.assert(caesar('Negative shift', shift=-1) == 'Mdfzshud rghes')
