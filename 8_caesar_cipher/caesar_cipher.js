var assert = require("assert");

/*
    @author Matteo Veraldi
    @github https://github.com/mattveraldi
    made for Hacktoberfest 2018!
*/

/**
 * Encrypt a text using caesar cypher algorithm.
 * this is the only function that the end user should call. 
 * @param {string} text - text to be encrypted.
 * @param {number} shift - number of letter's shifts.
 * @param {string} alphabetType - "latin" or "italian"
 * @returns {string} - encrypted text as string
 * 
 */ 
function caesar(text, shift, alphabetType) {
    var alphabet = alphabetSelector(alphabetType);
    try {
        parameterCheck(text, shift, alphabetType);
    }
    catch(err) {
        throw err;
    }
    finally {
        var textLower = text.toLowerCase();
        var textArr = textLower.replace(/\s/g, '').split("");
        for(var i = 0; i < textArr.length; i++) {
            var letter = textArr[i];
            var alphabetIndex = alphabet.indexOf(letter);
            if(alphabetIndex == -1){
                throw Error("letter not found in the chosen alphabet.");
            }
            textArr[i] = alphabet[(alphabetIndex + shift) % alphabet.length];
        }
        return textArr.join("");
    }
}

/**
 * UTILS:
 * here are all the variables/functions needed to make caesar cipher work.
 */

//alphabet types:
var latinAlphabet = "abcdefghijklmnopqrstuvwxyz".split("");
var italianAlphabet = "abcdefghilmnopqrstuvz".split("");

//alphabet selector
function alphabetSelector(alphabetType) {
    if(typeof(alphabetType) != "string") {
        return latinAlphabet;
    }
    switch(alphabetType.toLowerCase()) {
        case "latin":
            return latinAlphabet;
        case "italian":
            return italianAlphabet;
        default:
            return latinAlphabet;
    }
}

//check parameters type
function parameterCheck(text, shift, alphabetType){
    if(typeof(text) != "string" || typeof(alphabetType) != "string") {
        throw new TypeError("text and aplhabetType should be strings.");
    }
    if(typeof(shift) != "number") {
        throw new TypeError("shift should be a number.");
    }
}


module.exports = {"caesar": caesar};
