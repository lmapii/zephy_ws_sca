
```bash
$ mkdir .venv
$ PIPENV_VENV_IN_PROJECT=1 pipenv install --dev
```

```bash
$ source .venv/bin/activate

(.venv) $ west init --local --mf west-sdk-nrf.yml dev
(.venv) $ west update -o=--depth=1 -n

(.venv) $ pip install --upgrade pip
(.venv) $ pip install -r deps/zephyr/scripts/requirements.txt
```

Setup your SDK, then

```bash
(.venv) $ west build --no-sysbuild --board nrf52840dk/nrf52840 dev/app --pristine
```