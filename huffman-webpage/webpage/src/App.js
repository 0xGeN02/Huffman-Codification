import User from "./User";
import Footer from "./Footer";
import Navbar from "./Navbar";
import Hero from "./Hero";
import { BrowserRouter } from "react-router-dom";


const App = () => {
  return (
    <BrowserRouter>
      <Navbar />
          <Hero>
            <User />
          </Hero>    
      <Footer />
    </BrowserRouter>
  );
}


export default App;
