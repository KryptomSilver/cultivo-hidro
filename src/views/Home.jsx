import React from "react";
import ListSensors from "../components/ListSensors";

const Home = () => {
    return (
        <div className="container mt-4">
            <div className="row">
                <ListSensors />
            </div>
        </div>
    );
};

export default Home;
