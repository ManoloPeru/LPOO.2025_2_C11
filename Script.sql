CREATE TABLE Machine (
MachineId INT PRIMARY KEY,
Name VARCHAR(100),
Type VARCHAR(50),
State VARCHAR(50),
Location VARCHAR(100)
);
-- Insertar máquinas de ejemplo
INSERT INTO Machine VALUES (1, 'Brazo Robótico 1', 'Robótico', 'Operativa', 'Zona A-1');
INSERT INTO Machine VALUES (2, 'Sensor de Visión A2', 'Sensorial', 'En Mantenimiento', 'Zona B-
3');
INSERT INTO Machine VALUES (3, 'Actuador Hidráulico X', 'Actuador', 'Operativa', 'Zona C-2');

CREATE TABLE Maintenance (
    MaintenanceId INT IDENTITY(1,1) PRIMARY KEY,
    MachineId INT,
    Type VARCHAR(20),
    Date VARCHAR(10),
    State VARCHAR(10),
    Description VARCHAR(200),
    Cost  DECIMAL(10,2) NULL
);
GO

-- PROCEDIMIENTO PARA INSERTAR UNA MÁQUINA
CREATE PROCEDURE usp_AddMachine
@MachineId INT,
@Name NVARCHAR(100),
@Type NVARCHAR(50),
@State NVARCHAR(50),
@Location NVARCHAR(100)
AS
BEGIN
INSERT INTO Machine (MachineId, Name, Type, State, Location)
VALUES (@MachineId, @Name, @Type, @State, @Location);
END;
GO
-- PROCEDIMIENTO PARA CONSULTAR TODAS LAS MÁQUINAS
CREATE PROCEDURE usp_QueryAllMachines
AS
BEGIN
SELECT * FROM Machine;
END;
GO
-- PROCEDIMIENTO PARA ACTUALIZAR DATOS DE UNA MÁQUINA
CREATE PROCEDURE usp_UpdateMachine
@MachineId INT,
@Name NVARCHAR(100),
@Type NVARCHAR(50),
@State NVARCHAR(50),
@Location NVARCHAR(100)
AS
BEGIN
UPDATE Machine
SET Name = @Name, Type = @Type, State = @State, Location = @Location
WHERE MachineId = @MachineId;
END;
GO
-- PROCEDIMIENTO PARA ELIMINAR UNA MÁQUINA
CREATE PROCEDURE usp_DeleteMachine
@MachineId INT
AS
BEGIN
DELETE FROM Machine WHERE MachineId = @MachineId;
END;
GO
-- DATOS DE EJEMPLO
EXEC usp_AddMachine 11, 'Brazo Robótico 1', 'Robótico', 'Operativa', 'Zona A-1';
EXEC usp_AddMachine 12, 'Sensor de Visión A2', 'Sensorial', 'En Mantenimiento', 'Zona B-3';
EXEC usp_AddMachine 13, 'Actuador Hidráulico X', 'Actuador', 'Operativa', 'Zona C-2';

CREATE PROCEDURE usp_AddMaintenance
    @MachineId INT,
    @Type NVARCHAR(20),
    @Date NVARCHAR(10),
    @State NVARCHAR(10),
    @Description NVARCHAR(200),
    @Cost FLOAT
AS
BEGIN
    INSERT INTO Maintenance (MachineId, Type, Date, State, Description, Cost)
    VALUES (@MachineId, @Type, @Date, @State, @Description, @Cost);
    
    SELECT SCOPE_IDENTITY(); -- Retorna el MaintenanceId generado
END;
GO