
# Bootstrap in devcontainer

```bash
$ west init --local --mf west-sdk-nrf.yml dev
$ west update -o=--depth=1 -n
$ west build --board nrf52840dk/nrf52840 dev/app --pristine
```

# Local bootstrap

To develop locally ...

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

Setup your SDK (e.g., `source setup-sdk-nrf.sh`), then

```bash
(.venv) $ west build --board nrf52840dk/nrf52840 dev/app --pristine
(.venv) $ west build --board nrf52840dk/nrf52840 dev/app -DZEPHYR_SCA_VARIANT=codechecker
```

# Cppcheck

```bash
$ cppcheck \
    $(cat build/app/sca/cppcheck/cc-verbatim-args.txt) \
    --project=build/app/compile_commands.json \
    --enable=style \
    -i deps -i build \
    --suppress=*:*deps/*
```
