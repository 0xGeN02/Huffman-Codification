import React from "react";
import "./Undo.css"
const Undo =() =>{
    return(
        <div className="decoding-bg">
            <div className="decoding-head">
                <h2 className="decoding-h2">Decoded Message</h2>
                <div className="alphacode">
                    <h3 className="alphacode-h3">Alphabet Decodification:</h3>
                    <textarea>Your decoded message is:</textarea>
                    <button className="go-back-to-encode">Return to encode</button>
                </div>
            </div>
        </div>
    )
}

export default Undo;
