window.cipher = {
    encode: encode,
    decode: decode,
  };
  
  function encode(text, offset) { 
    let result = " ";
    for (let i = 0; i<text.length; i++) { 
      if (text[i].charCodeAt() == 32) {
        result += " ";
      }
  
      else if (text[i].charCodeAt() >= 65 && text[i].charCodeAt() <= 90) {
        result += String.fromCharCode(((text[i].charCodeAt()-65 + offset) % 26 ) + 65);   
      }
      else if (text[i].charCodeAt() >=97 && text[i].charCodeAt() <= 122) {
        result += String.fromCharCode(((text[i].charCodeAt()-97 + offset) % 26 ) + 97);
      }         
    }
        
    return result;
  }   
     
  function decode(text, offset) {
    let result2 = " ";
    for (let i = 0; i<text.length; i++) {
      if (text[i].charCodeAt() == 32) {
        result2 += " ";
      }
  
      else if (text[i].charCodeAt() >= 65 && text[i].charCodeAt() <= 90) {
        result2 += String.fromCharCode(((text[i].charCodeAt()-90 - offset) % 26 ) + 90);
      }
      else if (text[i].charCodeAt() >=97 && text[i].charCodeAt() <=122) {
        result2 += String.fromCharCode(((text[i].charCodeAt()-122 - offset) % 26) + 122);  
     
      }  
    }    
    return result2;
  }
  //example:
  //encode("caesarcipher", 5)
  //" hfjxfwhnumjw"
  //decode("hfjxfwhnumjw", 5)
  //" caesarcipher"
  