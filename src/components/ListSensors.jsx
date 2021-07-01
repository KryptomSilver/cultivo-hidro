import {
    faLightbulb,
    faRulerVertical,
    faTemperatureLow,
    faWater,
} from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import React, { Fragment } from "react";

const ListSensors = () => {
    return (
        <Fragment>
            <div className="col">
                <div
                    className="card text-white bg-info mb-3"
                    style={{ width: "20rem", height: "13.5rem" }}
                >
                    <h1
                        className="card-header text-center"
                        style={{ fontSize: "1.3rem" }}
                    >
                        Sensor de luz
                    </h1>
                    <div className="card-body d-flex flex-column align-items-center justify-content-around">
                        <FontAwesomeIcon
                            icon={faLightbulb}
                            style={{
                                textAlign: "center",
                            }}
                            size="3x"
                        />
                        <p className="card-text mt-3">Estado: Encendido</p>
                    </div>
                </div>
            </div>
            <div className="col">
                <div
                    className="card text-white bg-info mb-3"
                    style={{ width: "20rem", height: "13.5rem" }}
                >
                    <h1
                        className="card-header text-center"
                        style={{ fontSize: "1.3rem" }}
                    >
                        Sensor de temperatura
                    </h1>
                    <div className="card-body d-flex flex-column align-items-center justify-content-around">
                        <FontAwesomeIcon
                            icon={faTemperatureLow}
                            style={{
                                textAlign: "center",
                            }}
                            size="3x"
                        />
                        <p className="card-text mt-3">Estado: En mantenimiento</p>
                        <p className="card-text">Valores: 17&#176;</p>
                    </div>
                </div>
            </div>
            <div className="col">
                <div
                    className="card text-white bg-info mb-3"
                    style={{ width: "20rem", height: "13.5rem" }}
                >
                    <h1
                        className="card-header text-center"
                        style={{ fontSize: "1.3rem" }}
                    >
                        Sensor de nivel de agua
                    </h1>
                    <div className="card-body d-flex flex-column align-items-center justify-content-around">
                        <FontAwesomeIcon
                            icon={faWater}
                            style={{
                                textAlign: "center",
                            }}
                            size="3x"
                        />
                        <p className="card-text mt-3">Estado: Encendido</p>
                        <p className="card-text">Valores: 50%</p>
                    </div>
                </div>
            </div>
            <div className="col">
                <div
                    className="card text-white bg-info mb-3"
                    style={{ width: "20rem", height: "13.5rem" }}
                >
                    <h1
                        className="card-header text-center"
                        style={{ fontSize: "1.3rem" }}
                    >
                        Sensor de ph
                    </h1>
                    <div className="card-body d-flex flex-column align-items-center justify-content-around">
                        <FontAwesomeIcon
                            icon={faRulerVertical}
                            style={{
                                textAlign: "center",
                            }}
                            size="3x"
                        />
                        <p className="card-text mt-3">Estado: Apagado</p>
                        <p className="card-text">Valores: 4</p>
                    </div>
                </div>
            </div>
        </Fragment>
    );
};

export default ListSensors;
