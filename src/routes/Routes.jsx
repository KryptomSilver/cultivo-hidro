import React from 'react'
import { BrowserRouter as Router, Switch, Route } from "react-router-dom";
import Nav from '../components/Nav';
import Home from '../views/Home';
const Routes = () => {
    return (
        <Router>
            <Nav/>
            <Switch>
                <Route exact component={Home} path="/"/>
            </Switch>
        </Router>
    )
}

export default Routes
