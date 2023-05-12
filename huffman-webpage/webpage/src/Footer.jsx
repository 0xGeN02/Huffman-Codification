import React from "react";
import cppLogo from "./assets/cppLogo.png"
import wasmLogo from "./assets/wasmLogo.jpg"
import emscriptenLogo from "./assets/emscriptenLogo.jpg";
import jsLogo from "./assets/jsLogo.png";
import reactLogo from "./assets/reactLogo.png";
import "./Footer.css";

const Footer = () => {
  return (
    <div className="footer-bg">
      <div className="footer-utilities">
      <div className="logo">
          <a href="https://en.wikipedia.org/wiki/C%2B%2B" target="_blank" rel="noopener noreferrer">
            <img src={cppLogo} alt="C++" />
          </a>
        </div>
        <div className="logo">
          <a href="https://developer.mozilla.org/en-US/docs/Web/JavaScript" target="_blank" rel="noopener noreferrer">
            <img src={jsLogo} alt="JavaScript" />
          </a>
        </div>
        <div className="logo">
          <a href="https://reactjs.org/" target="_blank" rel="noopener noreferrer">
            <img src={reactLogo} alt="React" />
          </a>
        </div>
        <div className="logo">
          <a href="https://emscripten.org/" target="_blank" rel="noopener noreferrer">
            <img src={emscriptenLogo} alt="Emscripten" />
          </a>
        </div>
        <div className="logo">
          <a href="https://webassembly.org/" target="_blank" rel="noopener noreferrer">
            <img src={wasmLogo} alt="WebAssembly" />
          </a>
        </div>
      </div>
    </div>
  );
};

export default Footer;