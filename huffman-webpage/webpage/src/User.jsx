import React, { useState } from "react";
import Alphabet from "./wasm/Emscripten-Compiled/Alphabet"; // Asegúrate de tener la ruta correcta hacia el archivo de la biblioteca Alphabet
import { Huffman, printHuffmanTree } from "./wasm/Emscripten-Compiled/Huffman"; // Asegúrate de tener la ruta correcta hacia el archivo de la biblioteca Huffman
import "./User.css";

function compareEncodings(text) {
  // Crea una instancia de la clase Alphabet
  const alphabet = new Alphabet(text);

  // Encode the text using alphabet encoding
  const alphabetEncoded = alphabet.encode(text);

  // Encode the text using Huffman encoding
  const huffmanEncoded = Huffman.encode(text);

  // Calculate the difference in memory
  const alphabetBytes = alphabetEncoded.length;
  const huffmanBytes = Math.ceil(huffmanEncoded.encodedText.length / 8);
  const savedBytes = alphabetBytes - huffmanBytes;

  // Convert saved bytes to decimal
  const savedDecimal = savedBytes < 0 ? null : savedBytes.toString(10);

  // Print the Huffman tree graph
  console.log("Huffman encoding tree:");
  printHuffmanTree(huffmanEncoded.tree);

  // Return the results
  return {
    alphabet: alphabetEncoded,
    huffman: huffmanEncoded.encodedText,
    savedBytes: savedBytes < 0 ? "impossible to rest" : savedBytes,
    savedDecimal,
  };
}

const User = () => {
  const [message, setMessage] = useState("");
  const [encodedMessageAlpha, setEncodedMessageAlpha] = useState("");
  const [encodedMessageHuffman, setEncodedMessageHuffman] = useState("");
  const [huffmanTree, setHuffmanTree] = useState("");
  const [comparisonResult, setComparisonResult] = useState(null);

  const handleEncode = () => {
    // Codificación mediante la rutina de Alphabet
    const alphabet = new Alphabet("abcdefghijklmnopqrstuvwxyz0123456789");
    const encodedTextAlpha = alphabet.encode(message);
    setEncodedMessageAlpha(encodedTextAlpha);

    // Codificación mediante la rutina de Huffman
    const { encodedText, tree } = Huffman.encode(message);
    setEncodedMessageHuffman(encodedText);
    setHuffmanTree(printHuffmanTree(tree)); // Establece el árbol de Huffman en formato de cadena

    // Comparar las codificaciones de Alphabet y Huffman
    const comparison = compareEncodings(message);
    setComparisonResult(comparison);


  };
  return (
    <div className="container">
      <div className="inputgroup">
        <img src="./assets/buzo.png" alt="buzo"/>
        <h2 className="encodetitle">Encode Your Message:</h2>
        <textarea
          value={message}
          onChange={(e) => setMessage(e.target.value)}
          placeholder="Imput a String without spaces...."
        ></textarea>
        <button onClick={handleEncode} className="encodebutton">
          Encode
        </button>
      </div>
      <div className="outputgroup">
        <h3 className="outputsubtitle">Alphabet Encode</h3>
        <textarea value={encodedMessageAlpha} readOnly></textarea>
        <h3 className="outputsubtitle">Huffman Encode</h3>
        <textarea value={encodedMessageHuffman} readOnly></textarea>
        {comparisonResult && (
          <div className="comparisonresult">
            <h3 className="comparationresult">Comparison Result</h3>
            <p>Alphabet-encoded Length: {comparisonResult.alphabet.length}</p>
            <p>Huffman-encoded Length: {comparisonResult.huffman.length}</p>
            <p>Saved Bytes (Decimal): {comparisonResult.savedDecimal}</p>
          </div>
        )}
      </div>
      <div className="treegraph">
        <h3 className="outputsubtitleTree">Huffman Tree Graph</h3>
        <pre>
          <code>{huffmanTree}</code>
        </pre>
      </div>
    </div>
  );
};

export default User;