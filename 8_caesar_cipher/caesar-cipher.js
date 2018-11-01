'use strict'

/**
 * 
 * @param {string} message 
 * @param {number} cipher 
 * @returns {string}
 */
const caesarEncode = (message, cipher) => {
  const sanitizedMessage = message
    .replace(/(\W|[0-9])/g, '')
    .toLowerCase()
    .split('');

  const alphabet = 'abcdefghijklmnopqrstuvwxyz'.split('');

  const encodedMessage = sanitizedMessage
    .map((char) => (alphabet[((alphabet.indexOf(char) + cipher) % alphabet.length)]))
    .join('');

  return encodedMessage;
};

/**
 * 
 * @param {string} encodedMessage 
 * @param {number} cipher 
 * @returns {string}
 */
const caesarDecode = (encodedMessage, cipher) => {
  const sanitizedMessage = encodedMessage
    .replace(/(\W|[0-9])/g, '')
    .toLowerCase()
    .split('');

  const alphabet = 'abcdefghijklmnopqrstuvwxyz'.split('');
  
  const decodedMessage = sanitizedMessage
    .map((char) => {
      const index = (alphabet.indexOf(char) - cipher);
      if (index >= 0) {
        return alphabet[index];
      }
      return alphabet[alphabet.length - Math.abs(index)];
    })
    .join('');

  return decodedMessage;
};
