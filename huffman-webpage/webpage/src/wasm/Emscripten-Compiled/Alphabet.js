export default class Alphabet {
    constructor(text) {
      this.alphabet = {};
      let index = 0;
      for (let i = 0; i < text.length; i++) {
        const char = text.charAt(i).toLowerCase();
        if (char.match(/[a-z0-9]/)) {
          if (!this.alphabet[char]) {
            if (index === 0) {
              this.alphabet[char] = "0";
            } else {
              this.alphabet[char] = this.toBinary(index);
            }
            index++;
          }
        }
      }
    }
  
    toBinary(number) {
      let binary = "";
      while (number > 0) {
        binary = (number % 2) + binary;
        number = Math.floor(number / 2);
      }
      while (binary.length < 6) {
        binary = "0" + binary;
      }
      return binary;
    }
  
    encode(text) {
      let result = "";
      for (let i = 0; i < text.length; i++) {
        const char = text.charAt(i).toLowerCase();
        if (char.match(/[a-z0-9]/)) {
          result += this.alphabet[char];
        }
      }
      return result;
    }
  
    decode(encodedText) {
        let result = "";
        let binary = "";
        for (let i = 0; i < encodedText.length; i++) {
            const char = encodedText.charAt(i);
            if (char === "0" || char === "1") {
            binary += char;
            if (binary.length === 6) {
                const index = parseInt(binary, 2);
                let decodedChar;
                if (index === 0) {
                decodedChar = " ";
                } else if (index >= 1 && index <= 26) {
                decodedChar = String.fromCharCode(index + 96);
                } else if (index >= 27 && index <= 36) {
                decodedChar = String.fromCharCode(index + 21);
                } else {
                throw new Error("Invalid character encoding: " + binary);
                }
                result += decodedChar;
                binary = "";
            }
            } else if (char.match(/[a-z]/i)) {
            throw new Error("Invalid character encoding: " + char);
            }
        }
        if (binary !== "") {
            throw new Error("Invalid character encoding: " + binary);
        }
        return result;
    }
  
    getKeyByValue(object, value) {
      return Object.keys(object).find(key => object[key] === value);
    }
  }