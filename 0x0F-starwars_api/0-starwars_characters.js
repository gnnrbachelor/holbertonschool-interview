#!/usr/bin/node
/**
 * Prints character namese
 * First argument is Movie ID
 */

const request = require('request');
function getCharacterName (characters, i) {
  if (i === characters.length) return;
  request(characters[i], (err, resp, body) => {
    if (err) console.log(err);
    else {
      console.log(JSON.parse(body).name);
      getCharacterName(characters, ++i);
    }
  });
}
request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  function (err, resp, body) {
    if (err) console.log(err);
    else {
      const characters = JSON.parse(body).characters;
      getCharacterName(characters, 0);
    }
  });
