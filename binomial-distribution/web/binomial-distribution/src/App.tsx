import React from 'react';
import logo from './logo.svg';
import { createField, createForm, Field } from 'mobx-easy-form';
import { Observer } from "mobx-react";
import { useMemo } from 'react';
import './App.css';

function App() {
  const {
    form,
    numberOfTrials,
    minimunNumbersOfSuccessDesired,
  } = useMemo(() => {
    const form = createForm({
      onSubmit({ values }) {
        console.log("Values:", values);
      },
    });

    const numberOfTrials: Field<string, number | undefined> = createField({
      id: "numberOfTrials",
      form,
      initialValue: "10",
      validate(numberOfTrials) {
        if (numberOfTrials.length > 0) {
          return { error: undefined, parsed: Number(numberOfTrials) };
        }

        return { error: "Number of trials (n) is required", parsed: undefined };
      },
    });

    const minimunNumbersOfSuccessDesired: Field<string, number | undefined> = createField({
      id: "minimunNumbersOfSuccessDesired",
      form,
      initialValue: "10",
      validate(minimunNumbersOfSuccessDesired) {
        if (minimunNumbersOfSuccessDesired.length > 0) {
          return { error: undefined, parsed: Number(minimunNumbersOfSuccessDesired) };
        }

        return { error: "Minimun numbers of success desired (x1) is required", parsed: undefined };
      },
    });

    const maximunNumbersOfSuccessDesired: Field<string, number | undefined> = createField({
      id: "maximunNumbersOfSuccessDesired",
      form,
      initialValue: "10",
      validate(maximunNumbersOfSuccessDesired, minimunNumbersOfSuccessDesired) {
        if (maximunNumbersOfSuccessDesired.length > 0 || minimunNumbersOfSuccessDesired.length > 0) {
          return { error: undefined, parsed: Number(maximunNumbersOfSuccessDesired) };
        }

        return { error: "Maximun numbers of success desired (x1) is required", parsed: undefined };
      },
    });

    return {
      form,
      numberOfTrials, /* n */
      minimunNumbersOfSuccessDesired, /* x1 */
      maximunNumbersOfSuccessDesired, /* x2 */
      probabilityOfGettingSuccessInOneTrial, /* p */
      //probabilityOfGettingAFailureInOneTrial, /* q = p - 1 */
    };
  }, []);

  return (
    <div className='App'>
      <header className='App-header'>
        <img src={logo} className='App-logo' alt='logo' />
        <p>
          Edit <code>src/App.tsx</code> and save to reload.
        </p>
        <a
          className='App-link'
          href='https://reactjs.org'
          target='_blank'
          rel='noopener noreferrer'
        >
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
